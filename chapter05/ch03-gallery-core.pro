TEMPLATE = subdirs

SUBDIRS += \
    gallery-core \
    gallery-desktop

galery-desktop.depends = gallery-core
