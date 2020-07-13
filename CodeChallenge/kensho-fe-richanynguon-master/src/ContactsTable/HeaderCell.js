import * as React from 'react';
import PropTypes from 'prop-types';
import {Button, InputGroup, Popover} from '@blueprintjs/core';

export default function HeaderCell(props) {
  return (
    <th className="headerCell">
      {props.name}
      {props.name === 'Name' && (
        <Popover>
          <Button icon="filter" minimal />
          <InputGroup
            value={props.nameFilter}
            onChange={props.onNameFilter}
            placeholder="Filter Rows"
            leftIcon="filter"
            autoFocus
          />
        </Popover>
      )}
    </th>
  );
}

HeaderCell.propTypes = {
  name: PropTypes.string,
  nameFilter: PropTypes.string,
  onNameFilter: PropTypes.func,
  type: PropTypes.oneOf(['category', 'number', 'string']),
};
