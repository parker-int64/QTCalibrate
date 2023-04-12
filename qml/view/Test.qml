import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import FluentUI

//FluScrollablePage{

//    title:"TableView"
//    leftPadding:10
//    rightPadding:10
//    bottomPadding:20
//    spacing: 0

//    Component.onCompleted: {
//        const columns = [

//                          {
//                              title: 'X',
//                              dataIndex: 'coord_2dx',
//                              width:100
//                          },
//                          {
//                              title: 'Y',
//                              dataIndex: 'coord_2dy',
//                              width:100
//                          },
//                          {
//                              title: '操作',
//                              dataIndex: 'action',
//                              width:100
//                          },
//                      ];
//        table_view.columns = columns
//        loadData(1,4)
//    }

//    FluTableView{
//        id:table_view
//        Layout.fillWidth: true
//        Layout.topMargin: 20
//        pageCurrent: 1
//        pageCount: 2
//        itemCount: 1
//        onRequestPage:
//            (page,count)=> {
//                loadData(page,count)
//            }
//    }

//    Component{
//        id:com_action
//        Item{
//            Row{
//                anchors.centerIn: parent
//                spacing: 10
//                FluFilledButton{
//                    text:"编辑"
//                    topPadding:3
//                    bottomPadding:3
//                    leftPadding:3
//                    rightPadding:3
//                    onClicked:{
//                        console.debug(dataModel.index)
//                        showSuccess(JSON.stringify(dataObject))
//                    }
//                }
//                FluFilledButton{
//                    text:"删除"
//                    topPadding:3
//                    bottomPadding:3
//                    leftPadding:3
//                    rightPadding:3
//                    onClicked:{
//                        showError(JSON.stringify(dataObject))
//                    }
//                }
//            }
//        }
//    }

//    function loadData(page,count){
//        const dataSource = []
//        for(var i=0;i< 4;i++){
//            dataSource.push({
//                                coord_2dx: 101.445,
//                                coord_2dy: 505.101,
//                                action: com_action
//                            })
//        }
//        table_view.dataSource = dataSource
//    }



//}

FluScrollablePage {
    Layout.fillWidth: true
    Layout.fillHeight: true
    Column {
        Repeater {
            model: 5 // 重复创建 5 个 Rectangle
            delegate: Rectangle {
                property int rectangleIndex: index // 自定义属性，用于存储 Rectangle 的索引
                color: "red" // 矩形的颜色，可以根据需要自定义
                width: 50 // 矩形的宽度，可以根据需要自定义
                height: 50 // 矩形的高度，可以根据需要自定义
                MouseArea {
                    anchors.fill: parent
                    onClicked: console.log(repeater.itemAt(index).rectangleIndex) // 输出矩形的索引
                }
            }
            id: repeater // 使用 id 属性为 Repeater 对象分配一个唯一的 ID
        }
    }
}
