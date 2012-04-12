#import "ZXBarcodeFormat.h"
#import "ZXOneDReader.h"

/**
 * <p>Encapsulates functionality and implementation that is common to UPC and EAN families
 * of one-dimensional barcodes.</p>
 * 
 * @author dswitkin@google.com (Daniel Switkin)
 * @author Sean Owen
 * @author alasdair@google.com (Alasdair Mackintosh)
 */

extern const int START_END_PATTERN[];
extern const int MIDDLE_PATTERN[];
extern const int L_PATTERNS[][4];
extern int L_AND_G_PATTERNS[][4];

@class ZXEANManufacturerOrgSupport, ZXResult, ZXUPCEANExtensionSupport;

@interface ZXUPCEANReader : ZXOneDReader {
  NSMutableString * decodeRowNSMutableString;
  ZXUPCEANExtensionSupport * extensionReader;
  ZXEANManufacturerOrgSupport * eanManSupport;
}

- (ZXBarcodeFormat) barcodeFormat;
- (BOOL) checkChecksum:(NSString *)s;
+ (int) decodeDigit:(ZXBitArray *)row counters:(int[])counters rowOffset:(int)rowOffset patterns:(int*[])patterns;
- (NSArray *) decodeEnd:(ZXBitArray *)row endStart:(int)endStart;
- (int) decodeMiddle:(ZXBitArray *)row startRange:(NSArray *)startRange result:(NSMutableString *)result;
- (ZXResult *) decodeRow:(int)rowNumber row:(ZXBitArray *)row startGuardRange:(NSArray *)startGuardRange hints:(NSMutableDictionary *)hints;
+ (NSArray *) findStartGuardPattern:(ZXBitArray *)row;
+ (NSArray *) findGuardPattern:(ZXBitArray *)row rowOffset:(int)rowOffset whiteFirst:(BOOL)whiteFirst pattern:(int[])pattern;

@end