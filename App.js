/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

 import React, {useState} from 'react';
 import {
   HomeNavigationStack,
 } from './src/navigation/HomeNavigationStack';
 import {Splashscreen} from './src/pages/SplashScreen';
 
 const App = () => {
   const [loadHomeScreen, setLoadHomeScreen] = useState(false);
   const screentoLoad = loadHomeScreen ? (
     <HomeNavigationStack />
   ) : (
     <Splashscreen setLoadHomeScreen={setLoadHomeScreen} />
   );
 
   return <>{screentoLoad}</>;
 };
 
 export default App;