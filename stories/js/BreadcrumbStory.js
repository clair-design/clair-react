import React from 'react'
import { storiesOf } from '@storybook/react'
import Stage from '../../src/Stage.bs'
import Breadcrumb from '../../src/Breadcrumb.bs'
import BreadcrumbItem from '../../src/BreadcrumbItem.bs'

storiesOf('Breadcrumb In JavaScript', module).add('breadcrumb', () => (
  <Stage>
    <Breadcrumb>
      <BreadcrumbItem>
        <a>Home</a>
      </BreadcrumbItem>
      <BreadcrumbItem>
        <a>Info</a>
      </BreadcrumbItem>
      <BreadcrumbItem>Detail</BreadcrumbItem>
    </Breadcrumb>

    <Breadcrumb divider={'|'}>
      <BreadcrumbItem>
        <a>Home</a>
      </BreadcrumbItem>
      <BreadcrumbItem>
        <a>Info</a>
      </BreadcrumbItem>
      <BreadcrumbItem>Detail</BreadcrumbItem>
    </Breadcrumb>
  </Stage>
))
