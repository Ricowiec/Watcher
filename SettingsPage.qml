import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Page {
    id: page

    Text {
        id: testText
        text: qsTr("Ta strona będzie umożliwiała w przyszłości min.:\n- Zmianę liczby wyszukiwanych elementów w SearchPage\n- Usuwanie obserwowanych przez siebie firm\n- Zmianę pomiędzy trybem nocnym a dziennym")
        anchors.centerIn: parent
        width: parent.width / 2
        font.pixelSize: page.font.pixelSize

        wrapMode: Text.WordWrap

        Component.onCompleted: {
            Qt.inputMethod.hide();
            Qt.inputMethod.reset();
        }
    }

}
