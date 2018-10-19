import React from 'react'
import { storiesOf } from '@storybook/react'
import Stage from '../../src/Stage.bs'
import Icon from '../../src/Icon.bs'
import { featherIcons } from '../../src/Feather.bs'

storiesOf('Icons In JavaScript', module)
  .add('icon', () => (
    <Stage>
      <div>
        <p>feather</p>
        <Icon
          type_='feather'
          name='github'
          color='#498ff2'
          size='36'
          valign='middle'
        />
      </div>
      <div>
        <p>iconfont</p>
        <Icon
          type_='icon'
          name='angular'
          color='red'
          size='3em'
          valign='middle'
        />
      </div>
      <div>
        <p>ligature</p>
        <Icon
          ligature
          type_='material-icons'
          name='face'
          color='#212121'
          size='3em'
          valign='middle'
        />
      </div>
    </Stage>
  ))
  .add('feather icons', () => {
    let iconWrapperStyle = {
      width: '10%',
      marginBottom: '1em',
      textAlign: 'center'
    }

    let icons = featherIcons.map(name => (
      <div style={iconWrapperStyle} key={name}>
        <Icon name={name} color='#afafaf' size='24' valign='middle' />
        <p>{name}</p>
      </div>
    ))

    let style = {
      display: 'flex',
      flexWrap: 'wrap',
      padding: '40px'
    }

    return <Stage><div style={style}>{icons}</div></Stage>
  })
