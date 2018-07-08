import QtQuick 2.4

MoveGridPageForm {
    /*videoPlayer1x1.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer1x2.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer1x3.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"

    videoPlayer2x1.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer2x3.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"

    videoPlayer3x1.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer3x2.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"
    videoPlayer3x3.videoSource: "e:/projects/slowmodisplay/videos/1.mp4"*/

    Component.onCompleted: {
        centralImage.source = settings.splashScreen();

        videoPlayer1x1.backgroundImage = settings.splashScreen();
        videoPlayer1x2.backgroundImage = settings.splashScreen();
        videoPlayer1x3.backgroundImage = settings.splashScreen();

        videoPlayer2x1.backgroundImage = settings.splashScreen();
        videoPlayer2x3.backgroundImage = settings.splashScreen();

        videoPlayer3x1.backgroundImage = settings.splashScreen();
        videoPlayer3x2.backgroundImage = settings.splashScreen();
        videoPlayer3x3.backgroundImage = settings.splashScreen();

        videoRotator.addMediaPlayer(videoPlayer1x1);
        videoRotator.addMediaPlayer(videoPlayer1x2);
        videoRotator.addMediaPlayer(videoPlayer1x3);

        videoRotator.addMediaPlayer(videoPlayer2x1);
        videoRotator.addMediaPlayer(videoPlayer2x3);

        videoRotator.addMediaPlayer(videoPlayer3x1);
        videoRotator.addMediaPlayer(videoPlayer3x2);
        videoRotator.addMediaPlayer(videoPlayer3x3);

        videoRotator.init();
    }
}
