import React, {Component} from 'react';
import {StyleSheet, Text, View} from 'react-native';
import CardConnect from 'react-native-card-connect';
import moment from 'moment';

export default class App extends Component {
  state = {
    status: 'starting',
    message: '--'
  };
  componentDidMount() {
    this.tokenizeCard()
  }
  async tokenizeCard() {

    try {

      const siteId = "fts";
      const cardNumber = "4111111111111111";
      const expiryDate = moment('12/22', 'MM/YY').toISOString();
      const cVc = "123";

      CardConnect.setupConsumerApiEndpoint(siteId + ".cardconnect.com:443");

      const token = await CardConnect.getCardToken(
        cardNumber,
        expiryDate,
        cVc
      );

      console.log(token)

    } catch (error) {

      console.log(error.toString());

    }
  }
  render() {
    return (
      <View style={styles.container}>
        <Text style={styles.welcome}>☆CardConnect example☆</Text>
        <Text style={styles.instructions}>STATUS: {this.state.status}</Text>
        <Text style={styles.welcome}>☆NATIVE CALLBACK MESSAGE☆</Text>
        <Text style={styles.instructions}>{this.state.message}</Text>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  welcome: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },
  instructions: {
    textAlign: 'center',
    color: '#333333',
    marginBottom: 5,
  },
});
