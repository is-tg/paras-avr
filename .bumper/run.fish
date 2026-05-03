#!/usr/bin/env fish

if not string match -q "*.bumper" (pwd); or [ (count $argv) -lt 1 ]
    echo "wrong dir or no argument"
    exit 1
end

function read_confirm
    while true
        read -p 'echo "Proceed? (Y/n):"' -l confirm

        switch $confirm
            case '' Y y
                return 0
            case N n
                return 1
        end
    end
end

# create archive
cd ..
cp -r cores/ boards.txt platform.txt ar/mcs51/
rm ar/mcs51/cores/n76e003/.clang*
tar -cJf ar/n76e003-core.tar.xz ar/mcs51/

# set bumper data
set newver $argv[1]
echo $newver >.bumper/newver
set hash (string split ' ' (sha256sum ar/n76e003-core.tar.xz))[1]
echo SHA-256:$hash >.bumper/hash
set bytes (string trim (wc -c < ar/n76e003-core.tar.xz))
echo $bytes >.bumper/size

# create new release
gh release create $newver ar/n76e003-core.tar.xz /home/tg/Documents/sdcc-patched/sdcc-install/opt/linux-bundle.tar.xz

# update index
cd .bumper
/home/tg/Documents/bumper/bin/bumper
diff ../package_nuvoton_index.json draft.json
if read_confirm
    cp draft.json ../package_nuvoton_index.json
end
