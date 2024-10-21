import { Link as RouterLink } from 'react-router-dom';

import styled from 'styled-components';

export const Link = styled(RouterLink)`
  margin: 10px 5px;
  text-align: center;
  color: #000000;
  text-decoration: none;

  &:hover {
    cursor: pointer;
  }
`;
