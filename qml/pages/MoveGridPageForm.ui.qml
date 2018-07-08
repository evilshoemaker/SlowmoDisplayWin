import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../controls"

Item {
    width: 400
    height: 400

    property alias videoPlayer1x1: videoPlayer1x1
    property alias videoPlayer1x2: videoPlayer1x2
    property alias videoPlayer1x3: videoPlayer1x3

    property alias videoPlayer2x1: videoPlayer2x1
    property alias videoPlayer2x3: videoPlayer2x3

    property alias videoPlayer3x1: videoPlayer3x1
    property alias videoPlayer3x2: videoPlayer3x2
    property alias videoPlayer3x3: videoPlayer3x3

    property alias centralImage: centralImage

    GridLayout {
        id: grid
        columnSpacing: 0
        rowSpacing: 0
        rows: 3
        columns: 3
        anchors.fill: parent

        VideoPlayer {
            id: videoPlayer1x1
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 1
            Layout.column: 1
        }

        VideoPlayer {
            id: videoPlayer1x2
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 1
            Layout.column: 2
        }

        VideoPlayer {
            id: videoPlayer1x3
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 1
            Layout.column: 3
        }

        VideoPlayer {
            id: videoPlayer2x1
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 2
            Layout.column: 1
        }

        VideoPlayer {
            id: videoPlayer2x3
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 2
            Layout.column: 3
        }

        VideoPlayer {
            id: videoPlayer3x1
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 3
            Layout.column: 1
        }

        VideoPlayer {
            id: videoPlayer3x2
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 3
            Layout.column: 2
        }

        VideoPlayer {
            id: videoPlayer3x3
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 3
            Layout.column: 3
        }

        Item {
            clip: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 2
            Layout.column: 2

            Image {
                id: centralImage
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
            }
        }
    }
}
