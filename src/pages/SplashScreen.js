import React, {useEffect} from 'react';

import {
  StyleSheet,
  Text,
  View,
} from 'react-native';

export const Splashscreen = props => {
  useEffect(() => {
    const interval = setInterval(() => {
      clearInterval(interval);
      props.setLoadHomeScreen(true);
    }, 5000);

    return () => {
      clearInterval(interval);
    };
  }, []);

  return (
    <View style={styles.container}>
      <Text>Spalsh screen New</Text>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {flex: 1, justifyContent: 'center', alignItems: 'center'},
});