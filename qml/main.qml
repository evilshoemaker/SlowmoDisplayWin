import QtQuick 2.11
import QtQuick.Controls 2.4

import "pages"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Slow")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        MoveGridPage {

        }

        Page2Form {
        }
    }

    /*footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }*/
}
