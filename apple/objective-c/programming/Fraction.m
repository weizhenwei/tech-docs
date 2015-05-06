#import <Foundation/Foundation.h>

@interface Fraction : NSObject

- (void) print;
- (void) setNumerator: (int) n;
- (void) setDenominator: (int) n;

@end

@implementation Fraction
{
    int numerator;
    int denominator;
}

-(void) print
{
    NSLog(@"%i/%i", numerator, denominator);
}

-(void) setNumerator: (int) n
{
    numerator = n;
}

-(void) setDenominator: (int) m
{
    denominator = m;
}

@end

int main(int argc, char *argv[]) {
    @autoreleasepool {
        Fraction *frac = [[Fraction alloc] init];

        [frac setNumerator: 2];
        [frac setDenominator: 3];
        [frac print];

    }

    return 0;
}




