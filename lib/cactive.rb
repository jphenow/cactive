require "cactive/version"

Dir.glob("lib/ext/**/*.bundle") { |f| require f.to_s.gsub(/\.bundle/, '') }

module Cactive
  # Your code goes here...
end
