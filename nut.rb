require 'date'

class NutTime
  def initialize(time = Time.now)
    @time = time.utc
  end

  def time
    "%02.03f" % ((@time.hour*3600 + @time.min*60 + @time.sec).to_f/1000)
  end

  def day
    "%03d" % (@time.to_date - last_vernal_equinox.to_date).to_i
  end

  def year
    last_vernal_equinox.year
  end

  def to_s
    "#{year} #{day} #{time} NUT"
  end

  def inspect
    "#<#{self.class.to_s}: #{to_s}>"
  end

  private

  def last_vernal_equinox
    year = @time.year
    lve  = Time.new(year, 3, 20)

    if lve > @time
     lve = Time.new(year - 1, 3, 20)
    end

    lve
  end
end

class Time
  def nut
    NutTime.new(self)
  end
end
