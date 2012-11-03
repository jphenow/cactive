require "bundler/gem_tasks"

require 'rake/extensiontask'

Rake::ExtensionTask.new('array_access') do |ext|
  ext.ext_dir = File.join 'ext', 'array', 'access'
  ext.lib_dir = File.join 'lib', 'cactive', 'ext', 'array'
end
