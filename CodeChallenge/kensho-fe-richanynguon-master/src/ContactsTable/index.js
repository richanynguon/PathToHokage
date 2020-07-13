import * as React from 'react';

import {getContacts} from '../api';

import ContactsTable from './ContactsTable';

export default class ContactsTableWrapper extends React.Component {
  state = {
    columns: null,
    contacts: null,
    isLoading: true,
  };

  componentDidMount() {
    this.fetchContacts();
  }

  fetchContacts() {
    getContacts().then(data => {
      this.setState({
        isLoading: false,
        contacts: data.rows,
        columns: data.metadata.columns,
      });
    });
  }

  render() {
    const {columns, contacts, isLoading} = this.state;
    return isLoading ? (
      <div>Loading...</div>
    ) : (
      <ContactsTable contacts={contacts} columns={columns} />
    );
  }
}
