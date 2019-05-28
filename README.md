#Developer document

##Table and content

1. Introduction
2.	Introduction of GUI
	* 2.1. Main window
	* 2.2. Serial port setting dialog
	* 2.3. Database setting dialog
	* 2.4. User setting dialog
	* 2.5. Document dialog
3. Application working flow
	* 3.1. Main window working flow
	* 3.2.	Serial port setting working flow
	* 3.3.	Database setting working flow
	* 3.4.	user setting working flow	
4. Program explanation
	* 4.1. Signal and slot
	* 4.2. QT libraries
	* 4.3. Important functions 


##1. Introduction

Ticket application is a QT GUI application. It communicate with ticket device with serial port, and it can query, insert, delete data in MySQL database.

##2. Introduction of GUI

###2.1. Main window
![main window](main_window.png)

####Setting buttons

* There are three setting buttons: ***serial port setting*** , ***User setting***, ***Database setting***.
* You can single click the button and enter the correspounding setting 
dialogs.

### Document buttons

* The help button is the button with question mark icon.
* You can single click the button and enter the ducumentation dialog

####Start and stop buttons

* When serial port and database setting is completed, you can click ***start*** button to
	* send a start signal to ticket device. 
	* start receiving user's RFID from ticket device.
* You can click ***stop*** button to
	* stop receiving user's RFID from ticket device
	* send a stop signal to ticket device.

####Line edits

* the users information in the database will be shown in these four line edits: ***RFID***, ***Name***, ***Period***, ***Payment***
* If the RFID read from serial port can not be found in database, the line edits will be clear.

####Message box
The application will pop error message in the following situations:

* Disconnected to the database.
* Disconnected to the ticket device. 

###2.2. Serial port setting dialog
![serial port setting dialog](serial_port_setting.png) 

You can single click **show available port** button and  choose port and baudrate in ***Port*** and ***Baudrate*** comboboxs. 

If successfully connect to the ticket device, it pops success message, otherwise it pops error message with error details.

###2.3. Database setting dialog
![database setting dialog](database_Setting.png)

You can enter the information of the database in Edits and click ***OK*** button.

If successfully connect to the database, it pops success message, otherwise it pops error message with error details.

###2.4. User setting dialog

![user setting dialog](user_setting.png)

####Add a user

You can enter the information of the user in ***Name, Period, Payment*** Edits, and then click ***Add user***  button. The new generated user will be shown immediately in the table in the right side.

####Remove a user

You can choose a user and click ***Remove User*** button. 

###2.5. Document dialog

![document dialog](document.png)

You can choose a title in left window and read the corresponding document in the right window.

##3. Application work flow

###3.1. Main window working flow
![serial port setting work flow](dia_mainWindow.png)
###3.2.	Serial port setting working flow

![serial port setting work flow](dia_serial_setting.png)

###3.3.	Database setting working flow

![database setting work flow](dia_database_setting.png)

###3.4.	user setting working flow

![serial port setting work flow](dia_user_setting.png)

##4. Program explanation

To Explan the idea, the QT Libraries, and some important functions in program

###4.1. Signal and slot

In Qt, we have an alternative to the callback technique: We use signals and slots. A signal is emitted when a particular event occurs. Qt's widgets have many predefined signals, but we can always subclass widgets to add our own signals to them. A slot is a function that is called in response to a particular signal. Qt's widgets have many pre-defined slots, but it is common practice to subclass widgets and add your own slots so that you can handle the signals that you are interested in.

for more information please enter <http://doc.qt.io/archives/qt-4.8/signalsandslots.html>

![QT signal and slot explan ](http://doc.qt.io/archives/qt-4.8/images/abstract-connections.png)

###4.2. QT libraries 

The following library was used in this program

QtSerialPort	<https://doc.qt.io/qt-5.10/qtserialport-index.html>

QSerialPortInfo	<http://doc.qt.io/qt-5/qserialportinfo.html>

QSqlDatabase		<http://doc.qt.io/qt-5/qsqldatabase.html>

QSqlQuery			<http://doc.qt.io/qt-5/qsqlquery.html>

QSqlTableModel	<http://doc.qt.io/qt-5/qsqltablemodel.html>

QSqlError			<http://doc.qt.io/qt-5/qsqlerror.html>

QFile				<http://doc.qt.io/qt-5/qfile.html>

QMessageBox		<http://doc.qt.io/qt-5/qmessagebox.html>

QSettings			<http://doc.qt.io/qt-5/qsettings.html>

QTextStream		<http://doc.qt.io/archives/qt-4.8/qtextstream.html>

QString 			<http://doc.qt.io/qt-5/qstring.html#toInt>

QDebug				<http://doc.qt.io/qt-5/qdebug.html#details>

QMainWindow		<http://doc.qt.io/archives/qt-4.8/qmainwindow.html>

QDialog			<http://doc.qt.io/archives/qt-4.8/qdialog.html>

###4.3. Important functions

####In mainwindow.c

``void MainWindow::readRFID()``

* ***readRFID()*** is a private slot function in class MainWindow. 
* when there are available data in serial port, the ***port*** (a QSerialPort member in MainWindow class) will emit a ***readyRead()*** signal. 
* when the slot readRFID() and the signal ***readRead()*** is connected, whenever ***readRead()*** signal is emited, system will call ***readRFID()*** function. Which means whenever there are available data in serial port, system will call ***readRFID()*** function.
* We connect signal ***readyRead()*** and slot function ***readRFID()*** 
in function`MainWindow::on_StartButton_clicked()`by:

	``connect(&this->port,SIGNAL(readyRead()),this,SLOT(readRFID)));``

* This slot function do the following tasks:
	1.	Read data from serial port
	2. If received data end with '\n' (end of string character) These received data compose a RFID. e.g. The port receive `100` and `05\n`, this two data compose a RFID`10005`.
	3. If a RFID is composed, the application connect to database
	4. After connecting to database successfully, it search user information according to the RFID
	5. Display the user information in the line edits in main window


``void MainWindow::searchUserInDatabase(QString RFID, User &user)``

1. This function create a Qsqlquery instance `qry`, its search string is: `SELECT* >FROM mydb.tickets WHERE RFID = :RFID`. `:RFID`is a variable, and it was bind with input parameter RFID.
2. if it find a user in database, The function will modify the members (name, period, payment) of the input parameter user.
