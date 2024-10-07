import React from 'react';
import { Link } from 'react-router-dom';

export const Home: React.FC = () => {
  return (
    <div>
      <h1>Goraj</h1>
      <ul>
        <li>
          <Link to='/automation'>Automation</Link>
        </li>
        <li>
          <Link to='/analytics'>Analytics</Link>
        </li>
        <li>
          <Link to='/settings'>Settings</Link>
        </li>
      </ul>
    </div>
  );
};
