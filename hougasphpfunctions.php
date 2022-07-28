<?php

/***
Basic header and footer, this will need moar work later
***/

$head1 = "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n  <meta charset=\"UTF-8\">\n  <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n  <title>";
  $head2 = "</title>\n  <link rel=\"stylesheet\" href=\"./styles.css\"></link>\n</head>\n<body>\n";
  $tail = "</body>\n</html>";

/***
Create a link txt to dest
***/

  function mklink($dest,$txt)
  {
    return "<a href=\"$dst\">$txt</a>\n";
  }

/***
Image tags for imglnk
***/

  function mkimg($imglnk)
  {
    return "<img src= \"$imglnk\"></img>\n";
  }

/***
Create list item takes for an array els
***/

  function listels($els)
  {
    $lis = '';
    foreach($els as $el)
      $lis = $lis."<li>$el</li>\n";
    return $lis;
  }

/***
Wrap orderd list around array els
***/

  function ollist($els)
  {
    return "<ol>\n".listels($els)."</ol>\n";
  }

/***
Wrap unordered list around array els
***/

  function ullist($els)
  {
    return "<ul>\n".listels($els)."</ul>\n";
  }

/***
Create a div with class class and internal payload payload
***/

  function mkdiv($class,$payload)
  {
    return "<div class=\"".$class."\">\n".$payload."</div>\n";
  }
?>