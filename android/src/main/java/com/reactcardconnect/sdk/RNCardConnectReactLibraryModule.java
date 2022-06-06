package com.reactbolt.sdk;

import com.bolt.consumersdk.CCConsumer;
import com.bolt.consumersdk.CCConsumerTokenCallback;
import com.bolt.consumersdk.domain.CCConsumerAccount;
import com.bolt.consumersdk.domain.CCConsumerCardInfo;
import com.bolt.consumersdk.domain.CCConsumerError;
import com.bolt.consumersdk.utils.CCConsumerCardUtils;
import com.bolt.consumersdk.utils.LogHelper;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;

import android.util.Log;

import com.google.gson.Gson;

public class RNCardConnectReactLibraryModule extends ReactContextBaseJavaModule {

    private static final String TAG = "CardConnect";

    public RNCardConnectReactLibraryModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    public String getName() {
        return "CardConnect";
    }

    @ReactMethod
    public void getCardToken(
      String cardNumber,
      String expiryDate,
      String cvv,
      final Promise promise
    ) {

        LogHelper.setEnable(true);
        LogHelper.setLogLevel(LogHelper.LogLevel.DEBUG);

        try {
            validateCardNumber(cardNumber);
            validateCvv(cvv);

            CCConsumerCardInfo mCCConsumerCardInfo = new CCConsumerCardInfo();
            mCCConsumerCardInfo.setCardNumber(cardNumber);
            mCCConsumerCardInfo.setExpirationDate("08/24");
            mCCConsumerCardInfo.setCvv(cvv);
            mCCConsumerCardInfo.setPostalCode("04092");

            // Log.v(TAG, new Gson().toJson(mCCConsumerCardInfo));

            CCConsumer.getInstance().getApi().generateAccountForCard(mCCConsumerCardInfo, new CCConsumerTokenCallback() {
                @Override
                public void onCCConsumerTokenResponseError(CCConsumerError ccConsumerError) {
                    // Log.v(TAG, new Gson().toJson(ccConsumerError));
                    promise.reject(new Exception(ccConsumerError.getResponseMessage()));
                }

                @Override
                public void onCCConsumerTokenResponse(CCConsumerAccount ccConsumerAccount) {
                    promise.resolve(ccConsumerAccount.getToken());
                }
            });
        } catch (ValidateException e) {
            promise.reject(e);
        }catch (Exception e){
            promise.resolve(e);
            e.printStackTrace();
        }
    }

    private void validateCardNumber(String cardNumber) throws ValidateException {
        if (!CCConsumerCardUtils.validateCardNumber(cardNumber)) {
            throw new ValidateException("Invalid CardNumber");
        }
    }

    private void validateCvv(String cvv) throws ValidateException {
        if (!CCConsumerCardUtils.validateCvvNumber(cvv)) {
            throw new ValidateException("Invalid CVV");
        }
    }

    private void validateExpiryDate(String expiryDate) throws ValidateException {
        try {
            String[] array = expiryDate.split("/");
            if (!CCConsumerCardUtils.validateExpirationDate(array[0], array[1])) {
                throw new ValidateException("Invalid ExpiryDate");
            }
        } catch (Exception e) {
            throw new ValidateException("Invalid ExpiryDate");
        }

    }

    @ReactMethod
    private void setupConsumerApiEndpoint(String url) {

        // CCConsumer.getInstance().getApi().setEndPoint("https://qa.cardconnect.com");
        // CCConsumer.getInstance().getApi().setEndPoint("https://fts.cardconnect.com:6443");

        // CCConsumer.getInstance().getApi().setEndPoint("https://fts-uat.cardconnect.com");

        CCConsumer.getInstance().getApi().setEndPoint(url);

        // CCConsumer.getInstance().getApi().setDebugEnabled(true);
    }
}
