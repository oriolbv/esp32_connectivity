
/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */
 import SmartConfig from 'react-native-smartconfig-quan';
 import React, {useState} from 'react';
 import type {Node} from 'react';
 import {
   SafeAreaView,
   ScrollView,
   StatusBar,
   StyleSheet,
   Text,
   Button,
   useColorScheme,
   View,
 } from 'react-native';
 
 import {
   Colors,
   DebugInstructions,
   Header,
   LearnMoreLinks,
   ReloadInstructions,
 } from 'react-native/Libraries/NewAppScreen';
 
 const App: () => Node = () => {

  const [log, setLog] = useState('log here');

  let foundDevice = false;

    const wifiName = '';
    //const wifiPass = 'EWYWYZYLFWMJMN';
    const wifiPass = '';
    // you can random bssid of wifi, but it need correct format
    const wifiBssid = '';

    // timeout not work with android, on android default is 45s
    const TIME_OUT_SMART_CONFIG = 30 * 1000; // 30s
   const isDarkMode = useColorScheme() === 'dark';
 
   const backgroundStyle = {
     backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
   };

   function config() {
    setLog('configuring...');
    foundDevice = false;

    SmartConfig.start(wifiName, wifiBssid, wifiPass, TIME_OUT_SMART_CONFIG, (event) => {
        console.log(event);
        console.log(wifiName + ", " + wifiPass + ", " + wifiBssid);
        let { eventName, data } = event;
        if (eventName === 'onFoundDevice') {
            foundDevice = true;
            data = JSON.parse(data);

            // data in event is ip of ESP
            setLog('Found device\nip: ' + data.ip + '\nbssid: ' + data.bssid);
        } else {
            if (!foundDevice) {
                setLog('Not found');
            }
        }
    });
}

   function stopConfig() {
    SmartConfig.stop();
    setLog('Stopped config');
    }
 
   return (
     <SafeAreaView style={backgroundStyle}>
       <StatusBar barStyle={isDarkMode ? 'light-content' : 'dark-content'} />
       <ScrollView
         contentInsetAdjustmentBehavior="automatic"
         style={backgroundStyle}>
         <Header />
         <View
           style={{
             backgroundColor: isDarkMode ? Colors.black : Colors.white,
           }}>
           <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
           <View style={{ flexDirection: 'row', justifyContent: 'center', marginTop: 100 }}>
           <Button title={'Start Config'} onPress={() => config()} />

            <View width={20} />

            <Button title={'Stop Config'} onPress={() => stopConfig()}/>
            </View>
          </View>
           
         </View>
       </ScrollView>
     </SafeAreaView>
   );
 };
 
 const styles = StyleSheet.create({
   sectionContainer: {
     marginTop: 32,
     paddingHorizontal: 24,
   },
   sectionTitle: {
     fontSize: 24,
     fontWeight: '600',
   },
   sectionDescription: {
     marginTop: 8,
     fontSize: 18,
     fontWeight: '400',
   },
   highlight: {
     fontWeight: '700',
   },
 });
 
 export default App;
 