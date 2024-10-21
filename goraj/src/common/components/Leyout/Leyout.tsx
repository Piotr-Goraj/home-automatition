import React from 'react';
import { Outlet } from 'react-router-dom';

import { RouterMenu } from '../RouterMenu/RouterMenu';

const Layout = () => {
  return (
    <div>
      <Outlet />
      <RouterMenu />
    </div>
  );
};

export default Layout;
