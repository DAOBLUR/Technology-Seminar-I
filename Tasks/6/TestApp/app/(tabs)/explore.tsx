import MaterialCommunityIcons  from '@expo/vector-icons/MaterialCommunityIcons';
import { AntDesign, SimpleLineIcons } from '@expo/vector-icons';
import { StyleSheet, View, Text } from 'react-native';

import React from 'react'
import ParallaxScrollView from '@/components/ParallaxScrollView';
import { ThemedText } from '@/components/ThemedText';
import { ThemedView } from '@/components/ThemedView';

export default function TabTwoScreen() {
  const [distance, setDistance] = React.useState("Loading...");
  const [color, setColor] = React.useState("#FFFFFF");

  React.useEffect(() => {
    const interval = setInterval(() => {
      fetch('https://sjh6zkwc-7286.brs.devtunnels.ms/api/ProximitySensor/GetDistance', {
        method: 'GET',
        headers: {
          Accept: '*/*',
        },
      })
      .then((response) => response.text())
      .then((data) => {
        console.log(parseInt(data));
        let value = parseInt(data);
        if(value < 6) {
          setColor("blue");
        } 
        else if(value > 5 && value < 11) {
          setColor("yellow");
        }
        else if(value > 10 && value < 16) {
          setColor("green");
        }
        else if(value > 15 && value < 21) {
          setColor("red");
        }
        else {
          setColor("#FFFFFF");
        }
        setDistance(data);
      })
      .catch((error) => console.error(error));
    }, 1000);
  
    return () => clearInterval(interval);
  }, []);
  

  return (
    <ParallaxScrollView
      headerBackgroundColor={{ light: '#D0D0D0', dark: '#353636' }}
      headerImage={<MaterialCommunityIcons size={310} name="robot-angry" style={styles.headerImage} />}>
      <ThemedView style={styles.titleContainer}>
        <ThemedText type="title">Spard</ThemedText>
      </ThemedView>

      <View style={{alignContent: 'center', flexDirection: 'row', backgroundColor: '#363346', padding: 20, borderRadius: 25}}>
        <View style={{backgroundColor: '#62A8FE', height: 50, width: 50, borderRadius: 25}}>
          <SimpleLineIcons name="energy" size={30} color="#FFFFFF" style={{margin: 'auto'}}/>
        </View>

        <View style={{marginHorizontal: 10, marginVertical: 'auto'}}>
          <Text style={{color:'#FFFFFF', fontWeight: 'bold'}}>63.2 kWh</Text>
          <Text style={{color:'#908E99'}}>Electricity usage this month.</Text>
        </View>

        <View style={{backgroundColor: '#262333', height: 50, width: 50, borderRadius: 25}}>
          <AntDesign name="arrowright" size={30} color="#FFFFFF" style={{margin: 'auto'}}/>
        </View>
      </View>

      <View style={{margin: 'auto', backgroundColor: '#363346', height: 200, width: 200, padding: 20, borderRadius: 100}}>
        <View style={{margin: 'auto'}}>
          <Text style={{color: color, fontWeight: 'bold', fontSize: 30}}>{distance}</Text>
        </View>
      </View>
    </ParallaxScrollView>
  );
}

const styles = StyleSheet.create({
  headerImage: {
    color: '#808080',
    bottom: -50,
    left: -30,
    position: 'absolute',
  },
  titleContainer: {
    flexDirection: 'row',
    gap: 8,
  },
});
