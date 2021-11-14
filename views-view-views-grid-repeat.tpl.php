<?php

/**
 * @file
 * Default view template to display content using views_grid_repeat layout_type.
 */

// Fit or fill the grid.
$layout_type = $options['layout_type'];

// Width of the column or content.
$layout_width_value = $options['layout_width_value'];

// Minimum height of content.
$layout_width_height = $options['layout_width_height'];

// Unit of measire for the content value i.e. px or em etc.
$layout_width_unit = trim($options['layout_width_unit']);

$css_style = '';
$css_style_post = '"';
$css_syle_fit = 'auto-fit';
$css_syle_fit = 'auto-fill';

$css_width_value = '';
if ($layout_width_value > 0) {
  $css_width_value = strval($layout_width_value) . $layout_width_unit;
  $css_style = 'style="display:grid;grid-template-columns:repeat(auto----, minmax(' . $css_width_value . ', 1fr));';

  $css_width_height = '';
  if ($layout_width_height > 0) {
    $css_width_height = strval($layout_width_height) . $layout_width_unit;
    $css_style .= ' min-height:' . $css_width_height . ';' . $css_style_post;
  }
}

switch ($layout_type) {
  
  case "fit_grid":
    $css_style = str_replace('auto----','auto-fit',$css_style);        
    print '<div class="grid-repeat-container-fit" ' . $css_style . '>';
    if (!empty($title)) {
      print "<h3>$title</h3>";
    }
    foreach ($rows as $id => $row) {
      if ($row_classes[$id]) {
        print '<div class="' . implode(' ', $row_classes[$id]) . '">' . $row . '</div>';
    }
  }
  print '</div>';
  break;

  case "fill_grid":
    $css_style = str_replace("auto----","auto-fill",$css_style);
    print '<div class="grid-repeat-container-fill" ' . $css_style . '>';
    if (!empty($title)) {
      print "<h3>$title</h3>";
    }
    foreach ($rows as $id => $row) {
      if ($row_classes[$id]) {
        print '<div class="' . implode(' ', $row_classes[$id]) . '">' . $row . '</div>';
      }
    }
    print '</div>';
  break;
}