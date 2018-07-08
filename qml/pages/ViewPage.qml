import QtQuick 2.4

ViewPageForm {
    id: root

    videoOutput.height: parent.height * 0.8
    videoOutput.width: parent.width * 0.8

    state: "hidden"
    visible: opacity != 0.0

    videoOutput.onScaleChanged: {
        console.log(videoOutput.scale)
    }

    player.onPlaying: {
        root.state = "visible"
    }

    player.onStopped: {
        root.state = "hidden"
    }

    transitions: [
        Transition {
            from: '*'; to: 'visible'

            SequentialAnimation {
                /*ScriptAction {
                    script: {
                        player.play();
                    }
                }*/

                NumberAnimation { properties: "opacity,scale"; easing.type: Easing.InQuad; duration: 300 }
            }
        },

        Transition {
            from: 'visible'; to: '*'
            SequentialAnimation {
                ScriptAction {
                    script: {
                        if (player.status !== MediaPlayer.Stopped)
                            player.pause();
                    }
                }

                NumberAnimation { properties: "opacity,scale"; easing.type: Easing.OutQuad; duration: 400 }
            }
        }
    ]

    function play(source) {
        videoSource = source
        player.play()
    }
}
