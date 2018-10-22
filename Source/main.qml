import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 480
    height: 800
    title: qsTr("Obserwator")

//    property string globalBackgroundColor: "#6666cc"

    Drawer {
        id: leftMenuDrawer
//        width: window.width * 0.5
        width: window.width * 0.5 > homePageText.width + homePageImage.width * 2 ? window.width * 0.5 : homePageText.width + homePageImage.width * 2
        height: window.height
        dragMargin: parent.width * 0.085

        Column {
            anchors.fill: parent
            spacing: 0

            ItemDelegate {
                width: parent.width
                height: implicitHeight * 2
                background: Rectangle {
                    anchors.fill: parent
//                    color: "#6666cc"
                    gradient: Gradient {
                        GradientStop { position: 0.1; color: "#6666cc"; }
                        GradientStop { position: 2; color: "white" }
                    }
                }
            }

            ItemDelegate {
                width: parent.width

                Text {
                    id: homePageText
                    text: qsTr("Strona startowa")
                    color: "#6666cc"
                    font.pixelSize: parent.font.pixelSize
                    anchors.centerIn: parent
                }

                Image {
                    id: homePageImage
                    anchors.verticalCenter: parent.verticalCenter
                    x: homePageText.x / 2 - width / 2
                    width: homePageText.height * 1.8
                    height: homePageText.height * 1.8
                    mipmap: true
                    source: "/Menu/Icons/home.png"
                    fillMode: Image.Stretch
                }

                onClicked: {
                    stackView.push("HomePage.qml");
                    leftMenuDrawer.close();
                }
            }

            ItemDelegate {
                width: parent.width

                Text {
                    id: searchPageText
                    text: qsTr("Wyszukaj firmy")
                    color: "#6666cc"
                    font.pixelSize: parent.font.pixelSize
                    anchors.centerIn: parent
                }

                Image {
                    id: searchPageImage
                    anchors.verticalCenter: parent.verticalCenter
//                    x: searchPageText.x / 2 - width / 2
                    x: homePageImage.x
                    width: searchPageText.height * 1.8
                    height: searchPageText.height * 1.8
                    mipmap: true
                    source: "/Menu/Icons/loupe.png"
                    fillMode: Image.Stretch
                }

                onClicked: {
                    stackView.push("SearchPage.qml");
                    leftMenuDrawer.close();
                }
            }

            ItemDelegate {
                width: parent.width
//                Layout.preferredWidth: observedPageText.width + observedPageImage.width * 1.5
//                Layout.minimumWidth: observedPageText.width + observedPageImage.width * 1.5

                Text {
                    id: observedPageText
                    text: qsTr("Obserwowane")
                    color: "#6666cc"
                    font.pixelSize: parent.font.pixelSize
                    anchors.centerIn: parent
                }

                Image {
                    id: observedPageImage
                    anchors.verticalCenter: parent.verticalCenter
//                    x: observedPageText.x / 2 - width / 2
                    x: homePageImage.x
                    width: observedPageText.height * 1.8
                    height: observedPageText.height * 1.8
                    mipmap: true
                    source: "/Menu/Icons/spy2.png"
                    fillMode: Image.Stretch
                }

                onClicked: {
                    stackView.push("ObservedPage.qml");
                    leftMenuDrawer.close();
                }
            }

            ItemDelegate {
                width: parent.width

                Text {
                    id: settingsPageText
                    text: qsTr("Ustawienia")
//                    color: "#FF4D4D4D"
                    color: "#6666cc"
                    font.pixelSize: parent.font.pixelSize
                    anchors.centerIn: parent
                }

                Image {
                    id: settingsPageImage
                    anchors.verticalCenter: parent.verticalCenter
//                    x: settingsPageText.x / 2 - width / 2
                    x: homePageImage.x
                    width: settingsPageText.height * 1.8
                    height: settingsPageText.height * 1.8
                    mipmap: true
                    source: "/Menu/Icons/gear.png"
                    fillMode: Image.Stretch
                }

                onClicked: {
                    stackView.push("SettingsPage.qml");
                    leftMenuDrawer.close();
                }
            }

            ItemDelegate {
                width: parent.width

                Text {
                    id: helpPageText
                    text: qsTr("Pomoc")
//                    color: "#FF4D4D4D"
                    color: "#6666cc"
                    font.pixelSize: parent.font.pixelSize
                    anchors.centerIn: parent
                }

                Image {
                    id: helpPageImage
                    anchors.verticalCenter: parent.verticalCenter
//                    x: helpPageText.x / 2 - width / 2
                    x: homePageImage.x
                    width: helpPageText.height * 1.8
                    height: helpPageText.height * 1.8
                    mipmap: true
                    source: "/Menu/Icons/help.png"
                    fillMode: Image.Stretch
                }

                onClicked: {
                    stackView.push("HelpPage.qml");
                    leftMenuDrawer.close();
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomePage.qml"
        anchors.fill: parent

        Connections {
            target: APIBridge

            onPushedPage: {
//                console.log("Push Page");
                stackView.push("DetailedPage.qml")
            }

            onPopPage: {
                stackView.pop();
            }
        }
    }
}
