import time
import matplotlib.pyplot as plt
import random
from graph_helper import colors


def performance_tester(funcs, inputs, n=500000, ylim=True, multiple_inputs=False):
    total_performance = []
    for func in funcs:
        input_length = []
        performance = []
        color = colors[random.randrange(len(colors))-1]
        function_name = func.__name__
        for input in inputs:
            if multiple_inputs:
                total_duration = 0
                for i in range(n):
                    start = time.time()
                    func(*input)
                    end = time.time()
                    duration = end - start
                    total_duration += duration
                average_duration = total_duration/n
                performance.append(average_duration*10000)
                if type(input[0]) is not list and type(input[0]) is not dict:
                    if type(input[0]) == str:
                        all_length = 0
                        for i in input:
                            all_length += len(i)
                        input_length.append(all_length)
                    else:
                        input_length.append(sum(*input))
                else:
                    input_length.append(len(input))
            else:
                total_duration = 0
                for i in range(n):
                    start = time.time()
                    func(input)
                    end = time.time()
                    duration = end - start
                    total_duration += duration
                average_duration = total_duration/n
                performance.append(average_duration*10000)
                if type(input) is not list and type(input) is not dict:
                    if type(input) == str:
                        input_length.append(len(input))
                    else:
                        input_length.append(input)
                else:
                    input_length.append(len(input))
        total_performance.append({func.__name__: performance})
        plt.plot(input_length, performance, color=color,
                 linewidth=3, label=function_name)
        print("debugging reasons", color)
    if type(input) is not list and type(input) is not dict:
        if type(input) is str:
            plt.xlabel("String Length")
        else:
            plt.xlabel("Input Value")
    else:
        plt.xlabel('Amount of Elements')
    if ylim:
        plt.ylim([0, 1])
    plt.ylabel('Seconds')
    plt.legend()
    print(total_performance)
    plt.show()
    return "Done"
