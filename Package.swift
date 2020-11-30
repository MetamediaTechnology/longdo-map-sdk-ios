// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "LongdoMapSDK",
    platforms: [
        .macOS(.v10_15), .iOS(.v11)
    ],
    products: [
        .library(name: "LongdoMapSDK", targets: ["LongdoMapSDKBinaryPackage"])
    ],
    targets: [
        .binaryTarget(
            name: "LongdoMapSDKBinaryPackage",
            path: "LongdoMapSDK.xcframework"
        )
    ]
)