import QtQuick 2.7

MoveGridPageForm {
    videoPlayer1x1.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer1x2.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer1x3.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"

    videoPlayer2x1.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer2x3.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"

    videoPlayer3x1.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer3x2.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer3x3.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"

    Component.onCompleted: {
        centralImage.source = settings.splashScreen();

        /*videoPlayer1x1.backgroundImage = settings.splashScreen();
        videoPlayer1x2.backgroundImage = settings.splashScreen();
        videoPlayer1x3.backgroundImage = settings.splashScreen();

        videoPlayer2x1.backgroundImage = settings.splashScreen();
        videoPlayer2x3.backgroundImage = settings.splashScreen();

        videoPlayer3x1.backgroundImage = settings.splashScreen();
        videoPlayer3x2.backgroundImage = settings.splashScreen();
        videoPlayer3x3.backgroundImage = settings.splashScreen();

        videoGridViewer.addMediaPlayer(videoPlayer1x1);
        videoGridViewer.addMediaPlayer(videoPlayer1x2);
        videoGridViewer.addMediaPlayer(videoPlayer1x3);

        videoGridViewer.addMediaPlayer(videoPlayer2x1);
        videoGridViewer.addMediaPlayer(videoPlayer2x3);

        videoGridViewer.addMediaPlayer(videoPlayer3x1);
        videoGridViewer.addMediaPlayer(videoPlayer3x2);
        videoGridViewer.addMediaPlayer(videoPlayer3x3);

        videoGridViewer.init();*/
    }
}
