#include "tabbar_demo.h"
#include <QTabBar>
#include <QComboBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QFormLayout>

TabBarWindow::TabBarWindow(QWidget *parent)
    : QWidget(parent)
{
    QComboBox* shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("rounded north"), QTabBar::RoundedNorth);
    shapeComboBox->addItem(tr("rounded south"), QTabBar::RoundedSouth);
    shapeComboBox->addItem(tr("rounded west"), QTabBar::RoundedWest);
    shapeComboBox->addItem(tr("rounded east"), QTabBar::RoundedEast);
    shapeComboBox->addItem(tr("triangular north"), QTabBar::TriangularNorth);
    shapeComboBox->addItem(tr("triangular sourth"), QTabBar::TriangularSouth);
    shapeComboBox->addItem(tr("triangular west"), QTabBar::TriangularWest);
    shapeComboBox->addItem(tr("triangular east"), QTabBar::TriangularEast);

    QComboBox* buttonpositionbox = new QComboBox;
    buttonpositionbox->addItem(tr("left side"), QTabBar::LeftSide);
    buttonpositionbox->addItem(tr("right side"), QTabBar::RightSide);

    QCheckBox* documentModeBox = new QCheckBox;
    QCheckBox* closeableBox = new QCheckBox;
    
    tabbar = new QTabBar(this);
    QStringList tab_list{ "tab_one","tab_two","tab_three","tab_four" };
    for (int index = 0; index < tab_list.size(); index++)
    {
        tabbar->addTab(QIcon(":/icon/setting"), tab_list.at(index));
    }
    tabbar->setSelectionBehaviorOnRemove(QTabBar::SelectRightTab);
    
    QFormLayout* form_layout = new QFormLayout;
    form_layout->addRow(tr("Shape"), shapeComboBox);
    form_layout->addRow(tr("Button Position"), buttonpositionbox);
    form_layout->addRow(tr("Document Mode"), documentModeBox);
    form_layout->addRow(tr("Tab closeable"), closeableBox);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(form_layout);
    layout->addWidget(tabbar);

    connect(shapeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index) {
        int shape = shapeComboBox->itemData(index).toInt();
        tabbar->setShape(QTabBar::Shape(shape));
        });

    connect(buttonpositionbox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index) {
        int button_position = buttonpositionbox->itemData(index).toInt();
        });
    connect(closeableBox, &QCheckBox::stateChanged, this, [=](int state) {
        if (state == Qt::Checked)
            tabbar->setTabsClosable(true);
        else
            tabbar->setTabsClosable(false);
        });
    connect(documentModeBox, &QCheckBox::stateChanged, this, [=](int state) {
        switch (state)
        {
        case Qt::Unchecked:
            tabbar->setDocumentMode(false);
            break;
        case Qt::Checked:
            tabbar->setDocumentMode(true);
            break;
        default:
            tabbar->setDocumentMode(false);
            break;
        }
        });

    shapeComboBox->setCurrentIndex(0);
}

TabBarWindow::~TabBarWindow()
{

}