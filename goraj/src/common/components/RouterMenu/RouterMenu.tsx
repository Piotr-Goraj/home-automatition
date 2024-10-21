import React from 'react';

import * as S from '../../styles';
import { Background } from './styles';

export const RouterMenu = () => {
  return (
    <Background>
      <S.Link to='/'>home</S.Link>
      <S.Link to='/automations'>automations</S.Link>
    </Background>
  );
};
