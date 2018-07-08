import QtQuick 2.9
import QtMultimedia 5.9
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

Item {
    id: root

    property alias videoSource: player.source
    property alias backgroundImage: image.source

    //implicitWidth: 600
    //implicitHeight: 380

    Rectangle {
        anchors.fill: parent
        color: "#000"
    }

    Image {
        id: image
        source: root.backgroundImage
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
    }

    MediaPlayer {
        id: player
        source: root.videoSource
        autoLoad: true
        autoPlay: true
        muted: true
        loops: MediaPlayer.Infinite

        /*onPlaying: {
            root.playing = true;
        }

        onStopped: {
            root.playing = false;
        }

        onPositionChanged: {
            if (!audioProgress.pressed)
                audioProgress.value = player.position
        }*/

        onError: {
            console.log("Play error " + player.errorString);
            /*messageBox.informationAccept(qsTr("Внимание"), qsTr("Файл удален или поврежден. Выберите файл заново"),
                                      function() {
                                          if (isEdited) {
                                              player.stop();
                                              //fileDialog.open();
                                          }
                                      });*/
        }
    }

    VideoOutput {
        //id: videoOutput
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        source: player
        fillMode: VideoOutput.PreserveAspectCrop
    }
}
