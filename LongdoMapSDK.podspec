Pod::Spec.new do |s|
  s.name         = "LongdoMapSDK"
  s.version      = "3.22.1"
  s.summary      = "Integrated map tiles from Longdo Map to iOS application."
  s.description  = <<-DESC
 The SDK use map resources from Longdo.COM services yet allow developers to use other map tile standards such as TMS, WMS, and WMTS. The SDK provides most must have features allow developers to show markers on the map with a few lines. It also includes exclusive services such as POI tags but traffic events and traffic camera that aren't available on other map SDK.
                   DESC
  s.homepage     = "https://github.com/MetamediaTechnology/longdo-map-sdk-ios"
  s.screenshots  = "https://usermap.longdo.com/ipao/github_host/ss.png"
  s.documentation_url = "https://github.com/MetamediaTechnology/longdo-map-demo-ios/wiki"
  s.license      = { :type => "Commercial", :file => "LICENSE.md" }
  s.author             = { "Metamedia Technology" => "staff-map@mm.co.th" }
  s.social_media_url   = "https://www.facebook.com/longdocom"
  s.platform     = :ios
  s.ios.deployment_target = '11.0'
  s.source       = { :git => "https://github.com/MetamediaTechnology/longdo-map-sdk-ios.git", :tag => "#{s.version}" }
  s.vendored_frameworks = "LongdoMapSDK.xcframework"
  

end
