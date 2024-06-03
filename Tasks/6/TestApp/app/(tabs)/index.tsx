import { Image, StyleSheet, Pressable, TextInput, Text, Dimensions } from 'react-native';

import { HelloWave } from '@/components/HelloWave';
import ParallaxScrollView from '@/components/ParallaxScrollView';
import { ThemedText } from '@/components/ThemedText';
import { ThemedView } from '@/components/ThemedView';
import { Colors } from '@/constants/Colors';

export default function HomeScreen() {
  return (
    <ParallaxScrollView
      headerBackgroundColor = {{ light: '#A1CEDC', dark: '#1D3D47' }}
      headerImage = {
        <Image
          source={require('@/assets/images/partial-react-logo.png')}
          style={styles.reactLogo}
        />
      }>
      
      <ThemedView style={styles.titleContainer}>
        <ThemedText type="title">This is a demo application</ThemedText>
        <HelloWave/>
      </ThemedView>
      
      <ThemedView style={styles.stepContainer}>
        <Text style={{color:'white', fontSize:20}}>Username</Text>
        <TextInput
          placeholder='Input your username'
          cursorColor={'#000000'}
          style={{ height: 50, backgroundColor: 'white', paddingVertical: 10, paddingHorizontal: 15, fontSize: 15, borderRadius: 25, marginBottom: 10}}
        />

        <Text style={{color:'white', fontSize:20}}>Email</Text>
        <TextInput
          placeholder='Input your email'
          cursorColor={'#000000'}
          style={{ height: 50, backgroundColor: 'white', paddingVertical: 10, paddingHorizontal: 15, fontSize: 15, borderRadius: 25, marginBottom: 10}}
        />

        <Text style={{color:'white', fontSize:20}}>Password</Text>
        <TextInput
          placeholder='Input your password'
          cursorColor={'#000000'}
          secureTextEntry={true}
          style={{ height: 50, backgroundColor: 'white', paddingVertical: 10, paddingHorizontal: 15, fontSize: 15, borderRadius: 25, marginBottom: 10}}
        />

        <Pressable>
          {({pressed}) => (
              <Text style = { !pressed ? styles.signUp : styles.signUpPressed }> Sign Up </Text>
          )}
        </Pressable>
      </ThemedView>

      <Text style={{color:'white', fontSize:10}}>By Karlo Pacha Curimayhua</Text>
    </ParallaxScrollView>
  );
}

const styles = StyleSheet.create({
  signUp: {
      marginTop: 40,
      backgroundColor: Colors.appColor,
      width: Dimensions.get('screen').width * 0.8,
      paddingVertical: 10,
      borderRadius: 25,
      color: Colors.white,
      fontSize: 20,
      fontWeight: 'bold',
      textAlign: 'center'
  },
  signUpPressed: {
      marginTop: 40,
      backgroundColor: Colors.appColorPressed,
      width: Dimensions.get('screen').width * 0.8,
      paddingVertical: 10,
      borderRadius: 25,
      color: Colors.white,
      fontSize: 20,
      fontWeight: 'bold',
      textAlign: 'center'
  },
  titleContainer: {
    flexDirection: 'row',
    alignItems: 'center',
    gap: 8,
  },
  stepContainer: {
    gap: 8,
    marginBottom: 8,
  },
  reactLogo: {
    height: 178,
    width: 290,
    bottom: 0,
    left: 0,
    position: 'absolute',
  },
});
