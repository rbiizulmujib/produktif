#import <ScreenTime/ScreenTime.h>
#import <Foundation/Foundation.h>


- (void)blockURL:(NSString *)urlString {
    NSURL *url = [NSURL URLWithString:urlString];
    
    if (!url) {
        NSLog(@"Invalid URL");
        return;
    }

    // Create a webpage controller instance
    STWebpageController *webpageController = [[STWebpageController alloc] init];
    
    // Define the blocked URL as a category
    STWebpage *blockedWebpage = [[STWebpage alloc] initWithURL:url];
    STWebpageUsage *usage = [[STWebpageUsage alloc] initWithStartTime:[NSDate date] endTime:nil category:STAppCategoryIdentifierSocialNetworking];
    
    // Assign the webpage and block it
    webpageController.webpages = @[blockedWebpage];
    
    // Block the URL by setting a usage limit of 0 seconds
    [webpageController applyUsageLimit:usage completionHandler:^(NSError * _Nullable error) {
        if (error) {
            NSLog(@"Failed to block URL: %@", error.localizedDescription);
        } else {
            NSLog(@"URL successfully blocked");
        }
    }];
}
