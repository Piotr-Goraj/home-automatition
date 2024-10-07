import React from 'react';
import { Link } from 'react-router-dom';

export const Automations: React.FC = () => {
  return (
    <div>
      <h2>Automation</h2>
      <ul>
        <li>
          <Link to='/automation/aquarium'>Aquarium</Link>
        </li>
        <li>
          <Link to='/automation/staircase'>Staircase</Link>
        </li>
      </ul>
    </div>
  );
};
