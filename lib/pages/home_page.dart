import 'package:esp32_connectivity/pages/bluetooth_page.dart';
import 'package:esp32_connectivity/pages/general_page.dart';
import 'package:esp32_connectivity/pages/wifi_page.dart';
import 'package:flutter_blue/flutter_blue.dart';
import 'package:flutter/material.dart';

class HomePage extends StatefulWidget {
  const HomePage({Key? key, required this.title}) : super(key: key);

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  int _counter = 0;
  int _currentIndex = 0;
  List _listPages = [];
  Widget _currentPage = const GeneralPage(title: "General");
  
  @override
  void initState() {
    super.initState();
    _listPages
    ..add(GeneralPage(title: "General",))
    ..add(const BluetoothPage(title: "Bluetooth", state: BluetoothState.unknown,))
    ..add(WifiPage(title: "Wifi",));
    _currentPage = const GeneralPage(title: "General");
  }


  void _incrementCounter() {
    setState(() {
      // This call to setState tells the Flutter framework that something has
      // changed in this State, which causes it to rerun the build method below
      // so that the display can reflect the updated values. If we changed
      // _counter without calling setState(), then the build method would not be
      // called again, and so nothing would appear to happen.
      _counter++;
    });
  }

void _changePage(int selectedIndex) {
      setState(() {
        _currentIndex = selectedIndex;
        _currentPage = _listPages[selectedIndex];
      });
    }

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: Text(widget.title),
      ),
      body: SafeArea(
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: _currentPage,
        ),
      ),
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _currentIndex,
        items: const [
          BottomNavigationBarItem(
            icon: Icon(Icons.cake),
            label: 'General',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.sentiment_satisfied),
            label: 'Bluetooth',
          ),
            BottomNavigationBarItem(
            icon: Icon(Icons.access_alarm),
            label: 'Wifi',
          ),
        ],
        onTap: (selectedIndex) => _changePage(selectedIndex),
      ),
    );

    

  }
}
