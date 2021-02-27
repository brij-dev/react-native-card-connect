# react-native-card-connect

## Getting started

`$ npm install react-native-card-connect --save`

### Mostly automatic installation

For RN Version < 0.60 (no autolinking)

`$ react-native link react-native-card-connect`

For RN Version > 0.60 (with autolinking) nothing needs to be done other than installing the package.

## Usage
```javascript
import CardConnect from 'react-native-card-connect';
import moment from 'moment';

async tokenizeCard() {

  try {

    const siteId = "fts";
    const cardNumber = "42424242424242";
    const expiryDate = moment('12/22', 'MM/YY').toISOString();
    const cVc = "123";

    CardConnect.setupConsumerApiEndpoint(site_id + ".cardconnect.com:443");

    const token = await CardConnect.getCardToken(
      cardNumber,
      expiryDate
      cVc
    );

    console.log(token)

  } catch (error) {

    console.log(error.toString());

  }
```

## Additional Information

[CardConnect Mobile SDK](https://developer.cardconnect.com/mobile-sdks#get-a-token)
