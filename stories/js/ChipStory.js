import React from 'react'
import { storiesOf } from '@storybook/react'
import Stage from '../../src/Stage.bs'
import Icon from '../../src/Icon.bs'
import Chip from '../../src/Chip.bs'
import { presetColors, toLiteral as toColorLiteral } from '../../src/Color.bs'

class ChipClosabelDemo extends React.Component {
  state = { closed: false }

  render () {
    return (
      <Stage>
        {this.state.closed
          ? null
          : <Chip
            color='purple'
            closable
            label='closea chip'
            onClose={_ => this.setState({ closed: true })}
            />}
      </Stage>
    )
  }
}

storiesOf('Chip In JavaScript', module)
  .add('chip', () => (
    <Stage>
      {presetColors
        .map(toColorLiteral)
        .map(color => <Chip label={color} color={color} key={color} />)}
    </Stage>
  ))
  .add('size', () => (
    <Stage>
      <Chip label='small' size='sm' />
      <Chip label='normal' size='md' />
    </Stage>
  ))
  .add('close event', () => <ChipClosabelDemo />)
  .add('custom color', () => (
    <Stage>
      <Chip label='#336774' color={'#336774'} />
      <Chip label='#724832' color={'#724832'} />
      <Chip label='#516E41' color={'#516E41'} />
    </Stage>
  ))
  .add('custom content', () => (
    <Stage>
      <Chip color='blue'>
        <a href='https://twiter.com' target='_blank'>
          twitter
          <Icon name='arrowRight' color='#fff' />
        </a>
      </Chip>
    </Stage>
  ))
