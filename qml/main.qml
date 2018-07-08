import QtQuick 2.11
import QtQuick.Controls 2.4

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

    ViewPage {
        id: viewPage
        anchors.fill: parent
    }

    footer: TabBar {
        id: tabBar
        //currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
            onClicked: {
                viewPage.play("e:/projects/slowmodisplay/videos/1.mp4")
                //viewPage.state = "visible"

                //viewPage.videoSource = "e:/projects/slowmodisplay/videos/1.mp4"
            }
        }
        TabButton {
            text: qsTr("Page 2")
            onClicked: {
                viewPage.state = "hidden"
                //viewPage.videoSource = "e:/projects/slowmodisplay/videos/2.mp4"
            }
        }
    }

    Component.onCompleted: {

    }
}
