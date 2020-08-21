'''
Warning: Heiarchy levels cannot pass 5
'''

import sys
import pathlib
import os

GITHUB_URL_PREFIX = "https://github.com/richanynguon/PathToHokage/blob/master"
TAB=4

def create_index_files(index_data:object, folder_title:str, file_path: str):
    '''
    '''
    folder_path = file_path.rpartition("/")[0] + "/" + folder_title
    index_path = folder_path + "/" + folder_title + ".md"
    if(os.path.isfile(folder_path) is not True):
        os.mkdir(folder_path)
        with open(index_path,"w") as index:
            for line in index_data:
                index.write(index_data[line] + " "*2 +" \n")
    return folder_path
    
    
    

def create_subsection_files(subsection_data: object, folder_path: str):
    '''
    '''
    os.mkdir(f'{folder_path}/src')
    for i in range(len(subsection_data)):
        file_name = subsection_data[i][0].replace("# ","")
        file_name_hyphened = file_name.replace(" ","_")
        new_file_name = f'{folder_path}/src/{file_name_hyphened}.md'
        with open(new_file_name,"w") as index:
             for line in subsection_data[i]:
                index.write(subsection_data[i][line] + " "*2 +" \n")



def determine_heiarchy(line_data: str):
    '''
    '''
    counter=0
    for char in line_data:
        if char == " ":
            counter+=1
    return counter//TAB

def generate_index_data(file_object: object, path_add_on: str, folder_title:str):
    '''
    '''
    return_dict={}
    for idx, line in enumerate(file_object):
        line_heiarchy = determine_heiarchy(line)
  
        line= line.strip().replace("\n","")
        file_name = line.replace(" ", "_")
        data = None
        if idx == 0:
            data = f"# {line}"
        else:
            if line_heiarchy == 0:
                data = f"## [{line}]({GITHUB_URL_PREFIX}{path_add_on}/{folder_title}/src/{file_name}.md)" 
            else:
                data = (" " * TAB * (line_heiarchy-1))+ "- " + line

        return_dict[idx] =  data 
    return return_dict

def generate_dir_sect_dicts(file_object: object):
    '''
    '''
    sec_prefix = {
        1:"#",
        2:"##",
        3:"####",
        4:"######",
        5:"-"
    }
    directory_data={}
    section_data={}

    segment_counter = -1
    line_counter=0

    for idx, line in enumerate(file_object):
        line_heiarchy = determine_heiarchy(line)
        line= line.strip().replace("\n","")
        file_name = line.replace(" ", "-")
        if idx != 0:
            if line_heiarchy == 0:
                line_counter=0
                segment_counter+=1
                directory_data[segment_counter] = { 
                    line_counter: f"# {line}"
                }
                section_data[segment_counter] = {}
                line_counter+=1
            else:
                tab_spaces = " "*TAB*(line_heiarchy-1)
                directory_data[segment_counter][line_counter] = f"{tab_spaces}- [{line}](#{file_name})"
                suffix=""
                if line_heiarchy > 1 and line_heiarchy < 5 :
                    suffix="  \n---   \n"
                section_data[segment_counter][line_counter] = f"{sec_prefix[line_heiarchy]} {line}{suffix}"
                line_counter+=1 
    return {"segment_counter": segment_counter, "section_data":section_data, "directory_data": directory_data}

def generate_subsection_data(file_object: object):
    '''
    '''
    return_dict={}
    data_dict = generate_dir_sect_dicts(file_object)
    segment_counter = data_dict["segment_counter"]
    directory_data = data_dict["directory_data"]
    section_data = data_dict["section_data"]
    for i in range(segment_counter+1):
        dir_range = len(directory_data[i])
        sect_range = len(section_data[i])
        new_index = dir_range  
        return_dict[i] = {}
        return_dict[i].update(directory_data[i])
        for j in range(1, sect_range+1):
            return_dict[i][new_index] = section_data[i][j]
            new_index+=1   
    return return_dict
   
def determine_path_add_on(file_path: str):
    removed_dots = file_path.replace(".","")
    path = removed_dots.rpartition("/")[0]
    return path

def file_parser(file_path: str, folder_title:str):
    '''
    Params file_path: str, file path taking from args in command line
    Returns a parsed object from the file at given file path
    '''
    return_dict = { 
        "index_data":{},
        "subsection_data":{}
    }

    path_add_on = determine_path_add_on(file_path)
    with open(file_path, 'r') as file:
        index_dict = generate_index_data(file, path_add_on, folder_title)
        file.seek(0)
        subsection_dict = generate_subsection_data(file)
    file.close()
    return_dict["index_data"] = index_dict
    return_dict["subsection_data"] = subsection_dict
    return return_dict


def main():
    '''
    Requires two args during command run:
    first arg is the file path for the text file that needs to be used in the template creature
    second arg is the folder title that would like to be used
    ** The folder will be created on the same directory as the text file
    Returns newly created folder with a similar directory heiarchy
    ------------------------------------------
    |   folder_title                         |
    |       ->src                            |
    |           ->subsection.md              |             
    |           ->subsection.md              |
    |       ->index.md                       |
    ------------------------------------------
    '''
    if(len(sys.argv)>2):
        text_file = sys.argv[1]
        if(os.path.isfile(text_file)):
            folder_title = sys.argv[2]
            data_dict = file_parser(text_file, folder_title)
            folder_path = create_index_files(data_dict["index_data"], folder_title, text_file)
            create_subsection_files(data_dict["subsection_data"], folder_path)
        else:
            print("Path is not valid")
    else:
        print("Not enough arguments")

main()