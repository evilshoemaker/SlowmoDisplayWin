import QtQuick 2.7
import QtMultimedia 5.7

Item {
    id: root
    width: 400
    height: 400

    property alias videoOutput: videoOutput
    property alias videoSource: player.source
    property alias player: player

    Rectangle {
        anchors.fill: parent
        color: '#000'
        opacity: 0.9
    }

    MediaPlayer {
        id: player
        source: root.videoSource
        autoLoad: true
    }

    VideoOutput {
        id: videoOutput
        anchors.centerIn: parent
        source: player
        scale: 0
    }

    /*Item {
        id: testItem
        anchors.centerIn: parent

        Rectangle {
            anchors.fill: parent
            color: "blue"
        }
    }*/
    states: [
        State {
            name: "hidden"

            PropertyChanges {
                target: root
                opacity: 0
            }

            PropertyChanges {
                target: videoOutput
                scale: 0
            }
        },

        State {
            name: "visible"

            PropertyChanges {
                target: root
                opacity: 1
            }

            PropertyChanges {
                target: videoOutput
                scale: 1
            }
        }
    ]
}
