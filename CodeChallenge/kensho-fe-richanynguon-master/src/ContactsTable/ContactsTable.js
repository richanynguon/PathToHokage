import * as React from 'react';
import PropTypes from 'prop-types';
import {HTMLTable} from '@blueprintjs/core';

import HeaderCell from './HeaderCell';

export default class ContactsTable extends React.Component {
  static propTypes = {
    columns: PropTypes.arrayOf(
      PropTypes.shape({
        name: PropTypes.string,
        key: PropTypes.string,
        type: PropTypes.oneOf(['category', 'number', 'string']),
      })
    ),
    contacts: PropTypes.arrayOf(PropTypes.object),
  };

  state = {
    nameFilter: '',
  };

  handleNameFilter = event => {
    const nameFilter = event.target.value;
    this.setState({nameFilter});
  };

  render() {
    const {nameFilter} = this.state;
    const {columns, contacts} = this.props;
    const filteredContacts = nameFilter
      ? contacts.filter(contact =>
          contact.name.toUpperCase().includes(nameFilter.toUpperCase())
        )
      : contacts;
    return (
      <HTMLTable striped interactive>
        <thead>
          <tr>
            {columns.map(col => (
              <HeaderCell
                nameFilter={nameFilter}
                onNameFilter={this.handleNameFilter}
                {...col}
              />
            ))}
          </tr>
        </thead>
        <tbody>
          {filteredContacts.map(contact => (
            <tr key={contact.phone}>
              {columns.map(column => (
                <td key={column.key}>{contact[column.key]}</td>
              ))}
            </tr>
          ))}
        </tbody>
      </HTMLTable>
    );
  }
}
