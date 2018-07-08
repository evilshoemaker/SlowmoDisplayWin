import QtQuick 2.9
import QtQuick.Controls 2.2

//import esm 1.0

import "pages"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Slow")

    /*SwipeView {
        id: swipeView
        anchors.fill: parent
        //currentIndex: tabBar.currentIndex

        MoveGridPage {

        }

        Page2Form {
        }
    }*/

    MoveGridPage {
        anchors.fill: parent
    }

    /*ViewPage {
        id: viewPage
        anchors.fill: parent
    }*/

    footer: TabBar {
        id: tabBar
        //currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
            onClicked: {
                //videoRotator.active = true;
                //viewPage.play("e:/projects/slowmodisplay/videos/1.mp4")
                //viewPage.state = "visible"

                //viewPage.videoSource = "e:/projects/slowmodisplay/videos/1.mp4"
            }
        }
        TabButton {
            text: qsTr("Page 2")
            onClicked: {
                //videoRotator.active = false;
                //viewPage.state = "hidden"
                //viewPage.videoSource = "e:/projects/slowmodisplay/videos/2.mp4"
            }
        }
    }

    /*VideoRotator {
        id: videoRotator
        videoViewer: viewPage
        interval: settings.interval()
        videoGrid: videoGridViewer
    }*/
}
