//
//  MKMapView+Util.h
//  LongdoMap
//
//  Created by กมลภพ จารุจิตต์ on 21/10/58.
//  Copyright © พ.ศ. 2558 Metamedia Technology. All rights reserved.
//

@import MapKit;
#import "Annotation.h"

@protocol LMTagDelegate <NSObject>

- (void)tagData:(NSArray<LMTagAnnotation *> *)poi;
- (void)removeTagFromZoom:(NSInteger)zoom;

@end

@protocol LMSearchDelegate <NSObject>

- (void)searchData:(NSArray<LMPinAnnotation *> *)poi;
- (void)suggestData:(NSArray<NSString *> *)keyword;

@end

@protocol LMTileDataDelegate <NSObject>

- (void)dataFromTile:(NSData *)data;

@end

/*!
 @enum LMMode
 
 @discussion The LMMode enum defines constants that
 can be used to specify the type of map view.
 */
typedef NS_ENUM(NSInteger, LMMode) {
    ///Hillshade base layer.
    BASE,
    ///SPOT5 satellite base layer.
    GISTDA_SPOT5,
    ///Gray-ish base layer.
    GRAY,
    ///Basic base layer.
    HYDRO,
    ///MapQuest-OSM base layer.
    MAPQUEST,
    ///Standard base layer.
    NORMAL,
    ///Revert standard base layer.
    NORMALR,
    ///Open Cycle base layer.
    OPENCYCLE,
    ///Open Street Map base layer.
    OSM,
    ///Standard+POI base layer.
    POI,
    ///Political base layer.
    POLITICAL,
    ///Political base layer (No label).
    POLITICAL_NOLABEL,
    ///Bluemarble terrain base layer.
    TERRAIN,
    ///Thaichote satellite base layer.
    THAICHOTE,
    ///Thaichote satellite base layer.
    THAICHOTE_HTTP,
    ///Standard+POI non-base layer.
    POI_TRANSPARENT,
    ///Traffic non-base layer with auto-refresh.
    TRAFFIC,
    ///Offline layer. (Please contact company sales.)
    OFFLINE,
    ///Blank layer.
    BLANK,
    ///Longdo tag layer.
    TAG,
    ///Custom Layer.
    CUSTOM
};

/*!
@enum LMTileFormat

@discussion The LMTileFormat enum defines constants that
can be used to specify the type of custom map tile format.
*/
typedef NS_ENUM(NSInteger, LMTileFormat) {
    ///Web Map Service Format
    WMS,
    ///Tile Map Service Format
    TMS,
    ///Bounding Box Format
    BBOX
};

/*!
 @enum LMLanguage
 
 @discussion The LMLanguage enum defines constants that
 can be used to specify language of map view.
 */
typedef NS_ENUM(NSInteger, LMLanguage) {
    THAI,
    ENGLISH
};

@interface LMTileOverlayRenderer : MKTileOverlayRenderer {
    NSInteger oldZoom;
    NSMutableArray *pathOnMap;
}

@property (nonatomic, strong) NSArray *tag;
@property (nonatomic, assign) NSString *language;
@property (nonatomic, strong) NSString *apikey;
@property (nonatomic, assign) id <LMTagDelegate> delegate;

@end

@interface LMTileOverlay : MKTileOverlay {
    NSString *apikey;
    LMLanguage language;
    LMTileFormat tileFormat;
    NSString *modeName;
    NSString *urlLayer;
    NSString *urlForData;
}

@property (nonatomic, assign) LMMode mode;
@property (nonatomic, assign) id <LMTileDataDelegate> dataDelegate;

- (id)initWithMode:(LMMode)mode withKey:(NSString *)key andLanguage:(LMLanguage)lang;
- (void)setCustomUrl:(NSString *)urlString;
- (void)setTileFormat:(LMTileFormat)format;
- (void)loadDataFromURL:(NSString *)urlString;

@end

@interface LongdoMapView : MKMapView <LMTagDelegate, LMTileDataDelegate, MKMapViewDelegate> {
    LMTileOverlayRenderer *tagOverlay;
    NSString *apikey;
}

@property (nonatomic, assign) id <LMSearchDelegate> searchDelegate;
@property (nonatomic, assign) id <LMTileDataDelegate> dataDelegate;
@property (nonatomic, assign) LMLanguage language;

/**
 Initializes a `LongdoMapView` object with Longdo Map API Key.
 @param key Longdo Map API Key.
 */
- (void)setKey:(NSString *)key;

/**
 Get map current zoom.
 @return map current zoom.
 */
- (CGFloat)getZoomLevel;

/**
 Set map current zoom.
 @param zoomLevel the zoom of the map.
 */
- (void)setZoomLevel:(CGFloat)zoomLevel;

/**
 Get map span with specific zoom.
 @param zoomLevel the zoom of the map.
 @return span of the map with specific zoom.
 */
- (MKCoordinateSpan)coordinateSpanWithZoomLevel:(CGFloat)zoomLevel;

/**
 Add overlay layer to map view.
 @param overlayName overlay layer to be added.
 */
- (void)addLMOverlay:(LMMode)overlayName;

/**
 Add custom overlay layer to map view.
 @param urlString URL of layer to be added. (replace x,y position and zoom with {x}, {y}, {z} or bounding box with {w}, {s}, {e}, {n})
 @param tileFormat Tile format type.
 */
- (void)addCustomOverlayWithURL:(NSString *)urlString andFormat:(LMTileFormat)tileFormat;

/**
 Remove overlay layer from map view.
 @param overlayName overlay layer to be removed.
 */
- (void)removeLMOverlay:(LMMode)overlayName;

/**
 Show longdo tags on the map.
 @param tag array of tag name.
 */
- (void)showTags:(NSArray *)tag;

/**
 Remove longdo tags from the map.
 */
- (void)removeAllTags;

/**
 Fetch data from url specific by map area.
 @param urlString url for fetch data. (replace u,v,zoom position and zoom with {u}, {v}, {z})
 */
- (void)loadDataFromURL:(NSString *)urlString;

/**
 Search with Longdo map poi
 @param keyword word to search with Longdo
 @param location center of location to search with Longdo
 */
- (void)searchWithKeyword:(NSString *)keyword andCoordinate:(CLLocationCoordinate2D)location;

/**
 Suggest with Longdo map poi
 @param keyword word to suggest with Longdo
 */
- (void)suggestWithKeyword:(NSString *)keyword;

@end
