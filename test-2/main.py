# 导入所需的库
import sys
from PyQt5.QtWidgets import QLabel,QApplication, QWidget, QPushButton, QLineEdit
from PyQt5.QtWidgets import QMessageBox
from PyQt5.QtCore import pyqtSlot
import mysql.connector

# 创建一个类，表示我们的应用程序
class App(QWidget):
    def __init__(self):
        super().__init__()
        self.title = 'Delta Fund'
        self.initUI()
        self.show()  # 显示窗口

    def initUI(self):


        # 创建 QLabel 对象
        instrumentIdLabel = QLabel('Instrument ID:', self)
        exchangeLabel = QLabel('Exchange:', self)
        pointValueLabel = QLabel('Point Value:', self)
        currencyLabel = QLabel('Currency:', self)
        feeBpsLabel = QLabel('Fee Bps:', self)
        feeQtyLabel = QLabel('Fee Qty:', self)

        # 设置 QLabel 对象的位置
        instrumentIdLabel.move(100, 15)
        exchangeLabel.move(100, 55)
        pointValueLabel.move(100, 95)
        currencyLabel.move(100, 135)
        feeBpsLabel.move(100, 175)
        feeQtyLabel.move(100, 215)

        # 创建输入框和按钮
        self.instrumentId = QLineEdit(self)
        self.exchange = QLineEdit(self)
        self.pointValue = QLineEdit(self)
        self.currency = QLineEdit(self)
        self.feeBps = QLineEdit(self)
        self.feeQty = QLineEdit(self)

        # 设置控件的位置和大小
        
        
        self.instrumentId.setGeometry(250, 10, 200, 30)
        self.exchange.setGeometry(250, 50, 200, 30)
        self.pointValue.setGeometry(250,90, 200, 30)
        self.currency.setGeometry(250, 130, 200, 30)
        self.feeBps.setGeometry(250, 170, 200, 30)
        self.feeQty.setGeometry(250, 210, 200, 30)

        self.insert = QPushButton('Insert', self)
        self.insert.clicked.connect(self.on_click_insert)
        self.insert.setGeometry(10, 10, 80, 30)
        self.insert.hide()

        self.creatbutton = QPushButton('Create DB', self)
        self.creatbutton.clicked.connect(self.on_click_createdb)
        self.creatbutton.setGeometry(10, 100, 80, 30)
        self.creatbutton.hide()

        self.check_db_and_update_buttons()


    def check_db_and_update_buttons(self):
        db = mysql.connector.connect(user='root', password='password', host='localhost')
        cursor = db.cursor()
        cursor.execute("SHOW DATABASES LIKE 'test';")
        result = cursor.fetchone()

        if result:
            
            self.insert.show()
            self.creatbutton.hide()
        else:
            self.insert.hide()
            self.creatbutton.show()

        db.close()

    @pyqtSlot()


# ...

    def on_click_insert(self):

        instrumentId = self.instrumentId.text()
        exchange = self.exchange.text()
        pointValue = self.pointValue.text()
        currency = self.currency.text()
        feeBps = self.feeBps.text()
        feeQty = self.feeQty.text()

        # 连接到数据库
        db = mysql.connector.connect(user='root', password='password', host='localhost', database='test')

        # 创建一个游标
        cursor = db.cursor()

        try:
            # 插入数据到 Instrument 表
            cursor.execute("INSERT INTO Instrument (InstrumentId, Exchange, PointValue, Currency) VALUES (%s, %s, %s, %s)", (instrumentId, exchange, pointValue, currency))

            # 插入数据到 Fee 表
            cursor.execute("INSERT INTO Fee (InstrumentId, FeeBps, FeeQty) VALUES (%s, %s, %s)", (instrumentId, feeBps, feeQty))

            # 提交事务
            db.commit()
            self.instrumentId.clear()
            self.exchange.clear()
            self.pointValue.clear()
            self.currency.clear()
            self.feeBps.clear()
            self.feeQty.clear()
            QMessageBox.information(self, "Accept", f"Data insert successfully!")
        except Exception as err:
            QMessageBox.critical(self, "Error", f"An error occurred: {err}")
        

        finally:
            # 关闭数据库连接
            db.close()
            

            self.check_db_and_update_buttons()

    #
    def on_click_createdb(self):

        # 连接到数据库
        db = mysql.connector.connect(user='root', password='password', host='localhost', database='')

        # 创建一个游标
        cursor = db.cursor()

        cursor.execute("CREATE DATABASE IF NOT EXISTS test;")

        cursor.execute("USE test;")

        # 插入数据到Instrument表
        cursor.execute("CREATE TABLE Instrument ( \
            InstrumentId CHAR(16), \
            Exchange CHAR(8), \
            PointValue DOUBLE, \
            Currency CHAR(8), \
            PRIMARY KEY (InstrumentId) \
        );")

        cursor.execute("CREATE TABLE Fee ( \
            InstrumentId CHAR(16), \
            FeeBps DOUBLE, \
            FeeQty DOUBLE, \
            PRIMARY KEY (InstrumentId), \
            FOREIGN KEY (InstrumentId) REFERENCES Instrument(InstrumentId) \
        );")

        # 提交事务
        db.commit()

        # 关闭数据库连接
        db.close()
        
        QMessageBox.information(self, "Accept", f"Database created successfully!")
        self.check_db_and_update_buttons()


# 创建一个应用程序实例并运行
import os


app = QApplication(sys.argv)
ex = App()
sys.exit(app.exec_())