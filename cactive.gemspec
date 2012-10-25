# -*- encoding: utf-8 -*-
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'cactive/version'

Gem::Specification.new do |gem|
  gem.name          = "cactive"
  gem.version       = Cactive::VERSION
  gem.authors       = ["Jon Phenow"]
  gem.email         = ["j.phenow@gmail.com"]
  gem.description   = %q{}
  gem.summary       = %q{}
  gem.homepage      = ""

  gem.files         = `git ls-files`.split($/)
  gem.executables   = gem.files.grep(%r{^bin/}).map{ |f| File.basename(f) }
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.extensions    = Dir.glob "ext/**/*/extconf.rb"
  gem.require_paths = ["lib"]

  gem.add_development_dependency "rake-compiler"
end
