import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Page {
    id: page

    Text {
        id: testText
        text: qsTr("Ta strona w przyszłości będzie zawierała min.:\n- Numer kontaktowy\n- E-mail kontaktowy\n- Nr. GG\n- FAQ")
        anchors.centerIn: parent
        width: parent.width / 2
        font.pixelSize: page.font.pixelSize

        wrapMode: Text.WordWrap

        Component.onCompleted: {
            Qt.inputMethod.hide();
            Qt.inputMethod.setVisible(false);
        }
    }
}
