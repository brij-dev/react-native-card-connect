
#import "RNCardConnectReactLibrary.h"
#import <CardConnectConsumerSDK/CardConnectConsumerSDK.h>
#import <CardConnectConsumerSDK/CCCCardInfo.h>
#import <CardConnectConsumerSDK/CCCAccount.h>
#import <React/RCTLog.h>
#import <React/RCTConvert.h>

@implementation RNCardConnectReactLibrary

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

RCT_EXPORT_MODULE(CardConnect)

RCT_EXPORT_METHOD(setupConsumerApiEndpoint:(NSString *)endpoint) {
    [CCCAPI instance].endpoint = endpoint;
}

RCT_EXPORT_METHOD(getCardToken:(NSString *)cardNumber expirationDate:(NSString *)expirationDate CVV:(NSString *)CVV                   resolve: (RCTPromiseResolveBlock)resolve
rejecter:(RCTPromiseRejectBlock)reject)
{
    CCCCardInfo *card = [CCCCardInfo new];
    card.cardNumber = cardNumber;
    card.expirationDate = expirationDate;
    card.CVV = CVV;

    [[CCCAPI instance] generateAccountForCard:card completion:^(CCCAccount *account, NSError *error){
        if (account) {
            resolve(account.token);
        } else {
            reject(@"error", error.localizedDescription, error);
        }
    }];
}

@end
