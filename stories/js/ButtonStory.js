import React from 'react'
import { storiesOf } from '@storybook/react'
import Stage from '../../src/Stage.bs'
import Button from '../../src/Button.bs'
import ButtonGroup from '../../src/ButtonGroup.bs'

storiesOf('Button In JavaScript', module)
  .add('styles', () => (
    <Stage>
      <p>
        <Button>默认按钮</Button>
        <Button round>圆角风格</Button>
        <Button outline>线框风格</Button>
        <Button outline round>
          圆角线框
        </Button>
        <Button flat>扁平按钮</Button>
      </p>
      <p>
        <Button primary>主要操作</Button>
        <Button primary round>
          圆角风格
        </Button>
        <Button primary outline>
          线框风格
        </Button>
        <Button primary outline round>
          圆角线框
        </Button>
        <Button primary flat>
          扁平按钮
        </Button>
      </p>
      <p>
        <Button success>正向操作</Button>
        <Button success round>
          圆角风格
        </Button>
        <Button success outline>
          线框风格
        </Button>
        <Button success outline round>
          圆角线框
        </Button>
        <Button success flat>
          扁平按钮
        </Button>
      </p>
      <p>
        <Button warning>警告操作</Button>
        <Button warning round>
          圆角风格
        </Button>
        <Button warning outline>
          线框风格
        </Button>
        <Button warning outline round>
          圆角线框
        </Button>
        <Button warning flat>
          扁平按钮
        </Button>
      </p>
      <p>
        <Button danger>危险操作</Button>
        <Button danger round>
          圆角风格
        </Button>
        <Button danger outline>
          线框风格
        </Button>
        <Button danger outline round>
          圆角线框
        </Button>
        <Button danger flat>
          扁平按钮
        </Button>
      </p>
    </Stage>
  ))
  .add('disabled', () => (
    <Stage>
      <Button disabled>普通按钮</Button>
      <Button disabled outline>
        线框按钮
      </Button>
      <Button primary disabled>
        主操作按钮
      </Button>
      <Button primary disabled outline>
        线框主操作按钮
      </Button>
      <Button danger disabled>
        危险按钮
      </Button>
      <Button danger disabled outline>
        危险线框
      </Button>
      <Button disabled flat>
        扁平按钮
      </Button>
    </Stage>
  ))
  .add('size', () => (
    <Stage>
      <Button primary size='xs'>
        超小按钮
      </Button>
      <Button primary size='sm'>
        小号按钮
      </Button>
      <Button primary> 普通按钮 </Button>
      <Button primary outline size='lg'>
        大号按钮
      </Button>
      <Button primary outline size='xl'>
        超大号按钮
      </Button>
    </Stage>
  ))
  .add('loading', () => (
    <Stage>
      <Button loading>加载中</Button>
      <Button loading primary outline round>
        正在提交
      </Button>
      <Button danger loading flat>
        正在删除
      </Button>
    </Stage>
  ))
  .add('group', () => (
    <Stage>
      <ButtonGroup size='xs'>
        <Button>加粗</Button>
        <Button>斜体</Button>
        <Button>下划线</Button>
      </ButtonGroup>
      <ButtonGroup size='sm'>
        <Button outline icon='twitter' />
        <Button outline icon='facebook' />
        <Button outline icon='github' />
      </ButtonGroup>
      <ButtonGroup>
        <Button primary icon='bold' />
        <Button primary icon='italic' />
        <Button primary icon='repeat' />
      </ButtonGroup>
      <ButtonGroup>
        <Button primary outline>A</Button>
        <Button primary outline>B</Button>
        <Button primary outline>C</Button>
      </ButtonGroup>
      <ButtonGroup size='lg'>
        <Button danger>A</Button>
        <Button danger>B</Button>
        <Button danger>C</Button>
      </ButtonGroup>
      <ButtonGroup size='xl'>
        <Button danger outline>A</Button>
        <Button danger outline>B</Button>
        <Button danger outline>C</Button>
      </ButtonGroup>
    </Stage>
  ))
  .add('event', () => (
    <Stage>
      <Button
        primary
        outline
        icon='heart'
        onClick={_ => window.alert('Clicked')}
      />
    </Stage>
  ))
