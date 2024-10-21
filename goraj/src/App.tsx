import React from 'react';
import {
  createBrowserRouter,
  RouterProvider,
  RouteObject,
} from 'react-router-dom';

import { Home } from './apps/home/Home';
import { Automations } from './apps/automations/src/Automations';
import { Aquarium } from './apps/automations/src/aquarium/Aquarium';
import { Staircase } from './apps/automations/src/staircase/Staircase';
import { Analytics } from './apps/analytics/Analytics';
import { Settings } from './apps/settings/Settings';
import Layout from './common/components/Leyout/Leyout';

const App = () => {
  const routes: RouteObject[] = [
    {
      path: '/',
      element: <Layout />,
      children: [
        {
          path: '/',
          element: <Home />,
        },
        {
          path: '/automations',
          element: <Automations />,
        },
        {
          path: '/automations/aquarium',
          element: <Aquarium />,
        },
        {
          path: '/automations/staircase',
          element: <Staircase />,
        },
        {
          path: '/analytics',
          element: <Analytics />,
        },
        {
          path: '/settings',
          element: <Settings />,
        },
      ],
    },
  ];

  const router = createBrowserRouter(routes);

  return <RouterProvider router={router} />;
};

export default App;
