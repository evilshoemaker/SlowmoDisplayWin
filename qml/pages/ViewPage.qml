import QtQuick 2.4
import QtMultimedia 5.9

ViewPageForm {
    id: root

    signal playbackEnd()

    videoOutput.height: parent.height * 0.8
    videoOutput.width: parent.width * 0.8

    state: "hidden"
    visible: opacity != 0.0

    player.onPlaying: {
        root.state = "visible"
    }

    player.onStopped: {
        root.state = "hidden"
    }

    transitions: [
        Transition {
            from: '*'; to: 'visible'

            NumberAnimation { properties: "opacity,scale"; easing.type: Easing.InQuad; duration: 300 }
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

                ScriptAction {
                    script: {
                        root.playbackEnd();
                    }
                }
            }
        }
    ]

    function play(source) {
        videoSource = source
        player.play()
    }

    function stop() {
        player.pause()
        root.state = "hidden"
    }
}
