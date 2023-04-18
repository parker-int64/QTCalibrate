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
    id: pageTest
    title:"FlipView"
    leftPadding:10
    rightPadding:10
    bottomPadding:20
    spacing: 0

    FluArea{
        Layout.fillWidth: true
        height: 800
        paddings: 10
        Layout.topMargin: 20
        ColumnLayout{
            anchors.verticalCenter: parent.verticalCenter
            FluText{
                text:"水平方向的FlipView"
            }
            FluFlipView{
                width: 1200
                height: 800
                Image{
                    source: "qrc:/images/bg_mojave.jpg"
                    asynchronous: true
                    fillMode:Image.PreserveAspectCrop
                }
            }
        }
    }


}
