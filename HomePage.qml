import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Page {
    id: page

    Text {
        id: testText
        text: qsTr("Witaj w aplikacji Obserwator!\nNasza aplikacja pozwala na przejrzyste przeszukiwanie spisu KRS w poszukiwaniu interesujących cię firm.\n\nPo lewej znajduje się wysuwane menu które pozwala poruszać się po naszej aplikacji.")
        anchors.centerIn: parent
        width: parent.width / 2
        font.pixelSize: page.font.pixelSize

        wrapMode: Text.WordWrap

        Component.onCompleted: {
            Qt.inputMethod.hide();
        }
    }
}
